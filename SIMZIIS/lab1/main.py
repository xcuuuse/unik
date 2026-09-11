import random
import time
import itertools
import matplotlib.pyplot as plt

ALPHABET = ''.join(chr(code) for code in range(32, 127))
PASS_LENGTH = 4

def generate_string(length: int) -> str:
    random.seed(time.time())
    return ''.join(random.choice(ALPHABET) for _ in range(length))


def plot_frequency(text: str, filename: str="frequency.png"):
    codes = [ord(symbol) for symbol in ALPHABET]
    counts = [text.count(symbol) for symbol in ALPHABET]
    expected = len(text) / len(ALPHABET)
    plt.figure(figsize=(12, 5))
    plt.bar(codes, counts)
    plt.axhline(expected, color='red', linestyle='--', label='Expected frequency')
    plt.ylim(0, max(counts) * 1.3)
    plt.xlabel('ASCII code')
    plt.ylabel('Frequency')
    plt.title('Symbol frequency in the generated string')
    plt.legend()
    plt.savefig(filename, dpi=120)
    plt.close()


def crack(password: str) -> float:
    start_time = time.time()
    for candidate in itertools.product(ALPHABET, repeat=len(password)):
        if ''.join(candidate) == password:
            break
    return time.time() - start_time


def average_time(password_length: int, speed: float):
    return len(ALPHABET) ** password_length / 2 / speed


def plot_average_time(speed, max_length=16, filename="bruteforce_time.png"):
    lengths = list(range(1, max_length + 1))
    times = [average_time(length, speed) for length in lengths]
    plt.figure(figsize=(10, 6))
    plt.plot(lengths, times, marker='o')
    plt.yscale('log')
    plt.xticks(lengths)
    plt.xlabel('Password length')
    plt.ylabel('Average brute force time, seconds')
    plt.title('Average brute force time vs password length')
    plt.grid(alpha=0.3)
    plt.savefig(filename, dpi=120)
    plt.close()

length = int(input('String length: '))
text = generate_string(length)
plot_frequency(text)
counts = [text.count(symbol) for symbol in ALPHABET]
expected = len(text) / len(ALPHABET)
print(f'Expected: {expected:.1f} | min: {min(counts)} | max: {max(counts)}')
password = text[:PASS_LENGTH]
spent_time = crack(password)
print(f'Password: {password} | cracked in {spent_time:.3f} s')
speed = len(ALPHABET) ** PASS_LENGTH / crack(ALPHABET[-1] * PASS_LENGTH)
print(f'Speed: {speed:.0f} passwords per second')
for password_length in range(1, 17):
    print(f'Length {password_length:2d}: {average_time(password_length, speed):.3e} seconds')
plot_average_time(speed)
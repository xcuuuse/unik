#include <bits/stdc++.h>
#include <sys/wait.h>
using namespace std;

vector<string> split(const string &s)
{
   vector<string> tokens;
   istringstream iss(s);
   string token;

   while (iss >> token)
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main()
{
   string input;
   cout << "Simple command interpreter (type 'exit' to quit)\n";

   while(true)
   {
      cout << "$ ";
      getline(cin, input);

      if (input == "exit")
      {
         break;
      }
      
      if (input.empty())
      {
         continue;
      }
   
      vector<string> arguments = split(input);
      vector <char*> argv;
      for (auto& i: arguments)
      {
         argv.push_back(const_cast<char*>(i.c_str()));
      }
      argv.push_back(nullptr);

      pid_t pid = fork();

      if (pid == -1)
      {
         perror("fork falied");
         exit(1);
      }

      if (pid == 0)
      {
         if (execvp(argv[0], argv.data()) == -1)
         {
            perror("Execution failed");
            exit(1);
         }
      }
      else
      {
         int status;
         waitpid(pid, &status, 0);

      }
   }
   return 0;
}
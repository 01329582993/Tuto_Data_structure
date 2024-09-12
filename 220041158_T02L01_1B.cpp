#include <iostream>
#include <stack>
#include <string>
#include <vector>

//
//<html>
//  <head>
//    <title> title of webpage </title>
//  </head>
//  <body>
//    <p> This is a <b>paragraph</b> </p>
//  </body>
//</html>
//-1

//int n;
//vector<int>a;
//while(cin >> n)
//{
//    a.push_back(n);
//}
//

int main()
{
    char i;
    std::string code;
    std::string temp;
    std::string balise;


    for(int i=0 ; i<5; i++)
    {
        std::cin>>code[i];
    }

    for(char ch::code)
    {

        temp.clear();
        if(ch == '<')
        {
            temp += ch;
            if(ch == '>')
            {
                balise = temp;
                temp.clear();
            }
        }
        std::cout<<balise[0];

    }


    return 0;
}

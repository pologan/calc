#include "parser.h"

parser::parser()
{
    err = false;
    op_count = 0;
}

parser::~parser()
{
    //
}

bool parser::AddOperator (string name, int priority, direction dir, float (*func)(float,float))
{
    oper op;
    op.name = name;
    op.priority = priority;
    op.dir = dir;
    op.func = func;
    ops.push_back(op);
    op_count++;
}

bool IsOperator(string ch, oper * op)
{
    oper tmp = {"",-1,(direction)-1,0};
    * op = tmp;
    bool IsOperator = false;
    for(int i=0;i<op_count;i++)
    {
        if(ops[i].name==ch)
        {
            IsOperator = true;
            *op=ops[i];
            break;
        }
    }
    return IsOperator;
}

vector < string > parser::convertToONP(string exp)
{
    vector < string > out;
    vector< string > stack;

    int length = exp.size();
    string ch;
    string ch2;

    for (int i = 0;i<length;i++)
    {
        ch = exp[i];
        if( atoi( ch.c_str() ) <= 9 &&( atoi( ch.c_str() ) > 0 || ch == "0") )
        {
            // SYMBOL JEST CYFRĄ
            ch2 = exp[++i];
            string c = ch;
            while( atoi(ch2.c_str()) <= 9 && (atoi(ch2.c_str()) > 0 || ch2 == "0" || ch2 == "."))
            {
                c += ch2;
                ch2 = exp[++i];
                continue;
            }
            i--;
            out.push_back(c);
        }
        else if( atoi(ch.c_str()) <= 'z' && atoi(ch.c_str())>= 'a')
        {
            if(atoi(ch.c_str()) == 'x')
            {
                out.push_back(c);
            }
            // TODO: OBSŁUGA FUNKCJI I ZMIENNYCH :cc
        }
        else if(ch=="(")
        {
            // SYMBOL JEST LEWOSTRONNYM NAWIASEM
            stack.push_back(ch);
        }
        else if(ch==")")
        {
            // SYMBOL JEST PRAWOSTRONNYM NAWIASEM
           while(stack[stack.size() - 1] !="(")
           {
               out.push_back(stack[stack.size() - 1]);
               stack.pop_back();
           }
           stack.pop_back();
        }
        else
        {
            // SYMBOL JEST OPERATOREM
            oper cur;
            IsOperator(ch,&cur); //pobranie aktualnego operatora do zmiennej cur

            if(stack.size() <= 0)
            {
                //Nie ma operatorów na stosie
                stack.push_back(ch);
                continue;
            }

            oper op;
            while(IsOperator(stack[stack.size() - 1], &op)==true) //dopóki na stosie są operatory
            {
                if((cur.dir == ( direction) 0 && cur.priority <= op.priority ) || (cur.dir == (direction) 1 && cur.priority < op.priority))
                {
                    out.push_back(stack[stack.size() - 1]);
                    stack.pop_back();
                }
                else
                    break;

                if(stack.size() <= 0)
                {
                    break;
                }
            }
            stack.push_back(ch);
        }
    }
    while(stack.size()>0)
    {
        //Dodanie wszystkiego do wyjścia
        out.push_back(stack[stack.size() - 1]);
        stack.pop_back();
    }
    return out;
}


int parser::Parse(string exp)
{
    vector < string > symbols = convertToONP(exp);
    vector < string > stack;

    for(int i = 0; i < symbols.size();i++)
    {
        string sym = symbols[i];
        oper op;
        if(atoi(sym.c_str()) > 0 || sym=="0")
        {
            stack.push_back(sym);
        }
        else if(IsOperator(sym,&op))
        {
            string a = stack[stack.size()-1];
            stack.pop_back();
            string b = stack[stack.size()-1]
        }
        else if()
        {
            //TODO: Symbol jest funkcją
        }
    }
    string ret = "";
    ret = stack[0];
    return atoi( ret.c_str() );
}














































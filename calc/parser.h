#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef enum
{
    left,
    right
}direction;

class parser
{
private:
    struct oper
    {
        string name;
        int priority;
        direction dir;
        float( * func)(float,float);
    };
    
    vector <oper> ops;
    int op_count;
    bool err;
    
    bool IsOperator(string ch, oper * op);
    vector < string > convertToONP(string exp);

public:
    parser();
    ~parser();
    bool AddOperator (string name, int priority, direction dir, float (*func)(float,float));
    int Parse(string exp);
};

#endif // PARSER_H

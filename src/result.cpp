#include "result.h" 

void CreateOps() { 
ops["+"] = op_plus; 
ops["-"] = op_minus; 
ops["*"] = op_mul; 
ops["/"] = op_div; 
ops["^"] = op_deg; 
ops["opposite"] = op_opposite; 
ops["factorial"] = op_factorial; 
ops["%"] = op_odiv; 
ops["&"] = op_and; 
ops["|"] = op_or; 
ops["!"] = op_not; 
ops["sin"] = op_sin; 
ops["cos"] = op_cos; 
ops["tan"] = op_tan; 
ops["acos"] = op_acos; 
ops["asin"] = op_asin; 
ops["atan"] = op_atan; 

return; 
} 

void ResultExpr(tokens &pexpr, Variables &expvars, Massives &varmas) { 
    CreateOps(); 
    stack <double> s; 

    for (size_t i = 0; i < pexpr.size(); i++) { 
    switch (pexpr[i].type) { 
    case num: { 
        s.push(atoi(pexpr[i].name.c_str())); 
    } 
    break; 

    case var: { 
        Variables::iterator Vit; 
        for (Vit = expvars.begin(); Vit != expvars.end(); Vit++) { 
            if (Vit->first == pexpr[i].name) { 
                s.push(Vit->second); 
                break; 
            } 
        } 
    } 
    break; 

    case func: 
    case op: { 
        Ops::iterator Oit; 
        for (Oit = ops.begin(); Oit != ops.end(); Oit++) { 
            if (Oit->first == pexpr[i].name) { 
                s.push(Oit->second(s)); 
                break; 
            } 
        } 
    } 
    break; 

    case mas: { 
        int index = s.top(); 
        s.pop(); 

        Massives::iterator it; 
        for (it = varmas.begin(); it != varmas.end(); it++) { 
            if (it->first == pexpr[i].name) {
                s.push(it->second[index]); 
            }
        }
    }
    default: break;
    }
    }
    cout<<s.top()<<endl;
    s = stack <double>();
}

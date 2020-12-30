#include "symtab.h"
#include "scanner.h"

Attributes &Symbol_table::get(string name)
{
    if (is_declared(name))
    {
        return sym_tab.at(name);
    }
    error("Attribute does not exist");
}

void Symbol_table::set(string name, double nv)
{
    if (is_declared(name))
    {
        Attributes &at_set = get(name);
        if (at_set.is_const)
        {
            error("cannot change constant");
        }
        else
        {
            at_set.value = nv;
        }
    }
    return;
}

bool Symbol_table::is_declared(string name)
{
    if (sym_tab.count(name) > 0)
    {
        return true;
    }
    return false;
}

void Symbol_table::declare(string name, double nv, bool ic)
{
    sym_tab.insert(pair<string, Attributes>(name, Attributes(nv, ic)));
}

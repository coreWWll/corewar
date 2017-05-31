//
// Created by Anton Repnovskyi on 5/31/17.
//

#include "op.h"

void check_if_labels(t_asm *start)
{
    t_asm *p;

    p = start;
    while (p)
    {
        if (p->l_flag[0] == 1)
            find_label_or_die(start, start)
        p = p->next;
    }
}

void    validate_it(t_asm *start, t_op *d_tab)
{
    check_if_labels(start);

}
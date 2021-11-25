/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/25 18:29:48 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
int main(void)
{
    t_cmd_tab *table;
    
    table = init_command_table();    
    while (1)
    {
        create_prompt(table);   
    }    
}*/

void print_search(t_ht_tab* table, char* key) {
    char* val;
    if ((val = ht_search(table, key)) == NULL) {
        printf("%s does not exist\n", key);
        return;
    }
    else {
        printf("Key:%s, Value:%s\n", key, val);
    }
}
 
void print_table(t_ht_tab* table) {
    printf("\n-------------------\n");
    for (int i=0; i<table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s", i, table->items[i]->key, table->items[i]->value);
            if (table->overflow_buckets[i]) {
                printf(" => Overflow Bucket => ");
                t_linkdlst* head = table->overflow_buckets[i];
                while (head) {
                    printf("Key:%s, Value:%s ", head->item->key, head->item->value);
                    head = head->next;
                }
            }
            printf("\n");
        }
    }
    printf("-------------------\n");
}

int main()
{
    t_ht_tab* ht;

    ht = create_table(CAPACITY, NULL);
    ht_insert(ht, "1", "First address", NULL);
    ht_insert(ht, "2", "Second address", NULL);
    ht_insert(ht, "Hel", "Third address", NULL);
    ht_insert(ht, "Cau", "Fourth address", NULL);
    print_search(ht, "1");
    print_search(ht, "2");
    print_search(ht, "3");
    print_search(ht, "Hel");
    print_search(ht, "Cau");  // Collision!
    print_table(ht);
    ht_delete(ht, "1", NULL);
    ht_delete(ht, "Cau", NULL);
    print_table(ht);
    free_ht_tab(ht);
    return 0;
}
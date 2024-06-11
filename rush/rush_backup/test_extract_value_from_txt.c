/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_extract_value_from_txt.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrrodri <chrrodri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:04:05 by chrrodri          #+#    #+#             */
/*   Updated: 2024/04/06 12:12:05 by chrrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main()
{
    FILE * f = fopen("numbers.dict","r");
    int number;
    int res;
    while((res = fscanf(f, "%d,",&number)) != EOF){
        if(res == 1){
            printf("%d,", number);
        }
        else{
            fscanf(f,"%*[^,],");
        }
    }
    printf("\n");
    return 0;
}

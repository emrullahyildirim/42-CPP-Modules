/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:13:19 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/18 20:31:30 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int size, char **args)
{   
    if (size == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < size; i++)
        for (int j = 0; args[i][j]; j++)
            std::cout << (char) std::toupper(args[i][j]);
    std::cout << std::endl;
    return (0);
}
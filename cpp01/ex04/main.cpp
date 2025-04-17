/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:35:30 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/17 17:03:13 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int size, char **args)
{
	if (size == 4)
	{
		std::string fileName = args[1];
		std::string	searchFor = args[2];
		std::string	changeTo = args[3];
		
		std::fstream File(fileName);
		if (File.fail())
		{
			std::cout << "Couldn't open file: " << fileName << std::endl;
			return (EXIT_FAILURE);
		} 

		std::string	fileContent = "";
		std::string	buffer;
		while (std::getline(File, buffer))
		{
			fileContent += buffer;
			std::cout << buffer << std::endl;
		}
		File.close();
		std::ofstream newFile(fileName + ".replace");
		if (newFile.fail())
		{
			std::cout << "Couldn't open file: " << fileName << std::endl;
			return (EXIT_FAILURE);
		} 
		while (true)
		{
			size_t	index = fileContent.find(searchFor, 0);
			if (index == std::string::npos)
				break ;
			fileContent = fileContent.erase(index, searchFor.length());
			fileContent = fileContent.insert(index, changeTo);
		}
		newFile << fileContent;
		newFile.close();
	}
	else
		std::cout << "Usage: <File Name> <Search For> <Change For>" << std::endl;
	return (EXIT_SUCCESS);
}
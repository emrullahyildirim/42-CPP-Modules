/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyildir <emyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:35:30 by emyildir          #+#    #+#             */
/*   Updated: 2025/04/19 19:04:22 by emyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iostream>

void replace(std::string &str, std::string searchFor, std::string changeTo)
{
	while (true)
	{
		size_t	index = str.find(searchFor, 0);
		if (index == std::string::npos)
			break ;
		str = str.erase(index, searchFor.length());
		str = str.insert(index, changeTo);
	}
}


std::string	readFileContent(std::ifstream &file)
{
	bool		first = true;
	std::string	fileContent = "";
	std::string	buffer;
	while (std::getline(file, buffer, '\0'))
	{
		if (!first)
			fileContent += '\n';
		else 
			first = false;
		fileContent += buffer;
	}
	return (fileContent);
}

int	main(int size, char **args)
{
	if (size == 4)
	{
		std::string fileName = args[1];
		std::string searchFor = args[2];
		std::string changeTo = args[3];
		
		std::ifstream File(fileName.c_str());
		if (!File.is_open())
		{
			std::cout << "Couldn't open file: " << fileName << std::endl;
			return (EXIT_FAILURE);
		} 
		std::string	fileContent = readFileContent(File);
		File.close();
		std::ofstream newFile((fileName + ".replace").c_str());
		if (newFile.fail())
		{
			std::cout << "Couldn't open file: " << fileName << std::endl;
			return (EXIT_FAILURE);
		}
		replace(fileContent, searchFor, changeTo); 
		newFile << fileContent;
		newFile.close();
	}
	else
	{
		std::cout << "Usage: <File Name> <Search For> <Change For>" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
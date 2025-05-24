#include "Tasks.h"
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <algorithm>


void saveTaskToFile(const std::vector<Task>& tasks, const std::string& fileName)
{// create a file and write tasks to the file

	std::ofstream ostream(fileName);
	ostream << tasks.size();

	for (const Task& task : tasks) {
		std::string description = task.description;
		std::replace(description.begin(), description.end(), '_', ' '); //replace all ' ' with '_'

		ostream << '\n' << description << ' ' << task.done;
	}


}

std::vector<Task> loadTasksFromFile(const std::string& fileName)
{
	if (!std::filesystem::exists(fileName)) {
		return std::vector<Task>();
	}

	std::vector<Task> tasks; // create a vector of struct Task called tasks
	std::ifstream istream(fileName); // open the file for writing

	int n;
	istream >> n; // read the number of tasks
	for (int i = 0; i < n; i++) {
		std::string description;
		bool done;

		istream >> description >> done;
		std::replace(description.begin(), description.end(), '_', ' '); //replace all ' ' with '_'
		tasks.push_back(Task{ description, done });

	}


	return tasks;
}

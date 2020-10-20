#include "VLMain.h"

namespace VL {
	void VL_file::load(const std::string& VL_S_Location) {
		std::vector<std::string>* a = new std::vector<std::string>();
		std::fstream stream;
		stream.open(VL_S_Location, std::ios::in);
		if (stream.good()) {
			std::string str;
			while (std::getline(stream, str)) {
				a->push_back(str);
			}

			// checking all lines
			for (int i = 0; i < a->size(); i++) {

				std::string line = (*a)[i];

				std::string l_name = "";

				std::string l_value = "";
				if (line.length() > 0) {
					if (line[0] != '#') {
						// finding '=' in line
						/* starts with \ */

						if (line[0] == 0x5C) {
							this->V_list[this->V_list.size() - 1].value += " " + line.substr(1, line.size() - 1);
						}
						else {
							// finding '=' in line
							if (line.find('=') < line.length()) {
								int eqPos = strcspn(line.c_str(), "=");
								l_name = line.substr(0, eqPos);
								l_value = line.substr(eqPos + 1, line.size() - (eqPos + 1));
							}
							else {
								l_name = line;
							}
							V_list.push_back(VL_variable(l_name, l_value));
						}
					}
				}
			}

		}
		
		stream.close();
	
		delete a;
		a = NULL;
	}


	// ----- search functions -----

	std::string VL_file::getValue(const std::string& name) {
		for (int i = 0; i < V_list.size(); i++) {
			if (V_list[i].title == name)
				return V_list[i].value;
		}
		return "";
	}

	std::string VL_file::getValue(int index) {
		if (index < V_list.size())
			return V_list[index].value;
		return "";
	}

	int VL_file::getIndex(const std::string& name) {
		for (int i = 0; i < V_list.size(); i++) {
			if (V_list[i].title == name)
				return i;
		}
		return -1;
	}


	// ======================= HANDLER =======================

	// utility functions
	void VL_Handler::add(VL_variable* variable) {
		V_list.push_back(*variable);
	}

	std::string VL_Handler::getValue(const std::string& name) {
		for (int i = 0; i < V_list.size(); i++) {
			if (V_list[i].title == name)
				return V_list[i].value;
		}
		return "";
	}

	std::string VL_Handler::getValue(int index) {
		if (index < V_list.size())
			return V_list[index].value;
		return "";
	}

	int VL_Handler::getIndex(const std::string& name) {
		for (int i = 0; i < V_list.size(); i++) {
			if (V_list[i].title == name)
				return i;
		}
		return -1;
	}
}
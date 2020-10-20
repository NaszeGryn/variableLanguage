#include <string>
#include <vector>
#include <fstream>

namespace VL {
	// Variable struct
	struct VL_variable {
		// constructor
		VL_variable(const std::string& title, const std::string& value) {
			this->title = title;
			this->value = value;
		}

		// variables
		std::string title;
		std::string value;
	};


	// varialbe language file 
	class VL_file {
	public:
		//constructor
		VL_file(const std::string& VL_S_Location) {
			this->load(VL_S_Location);
		}

		// interpreter
		void load(const std::string& VL_S_Location);


		// ---- search functions ---- 

		std::string getValue(const std::string& name);

		std::string getValue(int index);

		int getIndex(const std::string& name);

	public:
		std::vector<VL_variable> V_list;
	};

	// combines variables from file to variable list
	static void combine(std::vector<VL_variable>* V_list, VL_file* file) {
		for (int i = 0; i < file->V_list.size(); i++) {
			V_list->push_back(file->V_list[i]);
		}
	}

	// variable handler
	class VL_Handler {
	public:
		VL_Handler() { ; }
		~VL_Handler() {
			V_list.clear();
		}

		// adds variables from file
		void addFromFile(const std::string& VL_S_Location) {
			VL_file* tempFile = new VL_file(VL_S_Location);
			VL::combine(&V_list, tempFile);

			delete tempFile;
			tempFile = NULL;
		}

		// adds variable
		void add(VL_variable* variable);

		std::string getValue(const std::string& name);

		std::string getValue(int index);
		int getIndex(const std::string& name);


	public:
		std::vector<VL_variable> V_list;
	};
}

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Math.hpp"

namespace Noatak{
	namespace LanguageProcessor{
		namespace Util{
			static std::vector<std::pair<std::string,std::vector<std::pair<std::string,std::string>>>> symbols;
			static std::vector<std::pair<std::string,std::vector<std::string>>> indexedCategories;
		}

		static bool BuildSymbols(std::string _languageFile){
			Util::symbols.clear();

			std::ifstream langFile;
			langFile.open(_languageFile);
			if(!langFile.is_open()){
				return false;
			}

			std::string line="";
			long long categoryIndex=-1;

			while(std::getline(langFile,line)){
				if(line.size()==0){
					continue;
				}

				std::string category="";
				bool regularCategory=line[0]=='.';
				bool indexedCategory=line[0]==',';

				if(regularCategory||indexedCategory){
					for(int index=1; index<line.size(); index++){
						category+=line[index];
					}

					Util::symbols.push_back(std::make_pair(category,std::vector<std::pair<std::string,std::string>>()));
					if(indexedCategory){
						Util::indexedCategories.push_back(std::make_pair(category,std::vector<std::string>()));
					}

					categoryIndex++;
				}
				else{
					std::string symbol="";
					std::string value="";
					bool writeValue=false;

					for(int index=0; index<line.size(); index++){
						if(line[index]==':'&&!writeValue){
							writeValue=true;
							continue;
						}

						writeValue?value+=line[index]:symbol+=line[index];
					}

					Util::symbols[categoryIndex].second.push_back(std::make_pair(symbol,value));
				}
			}

			for(int i=0; i<Util::indexedCategories.size(); i++){
				for(int j=0; j<Util::symbols.size(); j++){
					if(Util::indexedCategories[i].first==Util::symbols[j].first){
						for(int k=0; k<Util::symbols[j].second.size(); k++){
							Util::indexedCategories[i].second.push_back(Util::symbols[j].second[k].second);
						}
					}
				}
			}

			return true;
		}

		static const std::string Lookup(std::string _category,std::string _symbol){
			for(int categoryIndex=0; categoryIndex<Util::symbols.size(); categoryIndex++){
				if(Util::symbols[categoryIndex].first==_category){
					for(int symbolIndex=0; symbolIndex<Util::symbols[categoryIndex].second.size(); symbolIndex++){
						auto symbolPair=Util::symbols[categoryIndex].second[symbolIndex];
						if(symbolPair.first==_symbol){
							return symbolPair.second;
						}
					}
					return "Err: "+_symbol;
				}
			}
			return "Err: "+_category;
		}

		static const std::string TakeRandomValue(std::string _indexedCategory){
			for(int categoryIndex=0; categoryIndex<Util::indexedCategories.size(); categoryIndex++){
				if(Util::indexedCategories[categoryIndex].first==_indexedCategory){
					auto& values=Util::indexedCategories[categoryIndex].second;

					if(values.size()>0){
						int index=Math::RandomRange(0,static_cast<int>(values.size()));
						std::string value=values[index];
						values.erase(values.begin()+index);

						return value;
					}
					else{
						return "Err:"+_indexedCategory;
					}
				}
			}

			return "Err:_indexedCategory";
		}
	}
}

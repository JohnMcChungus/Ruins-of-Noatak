#pragma once

namespace eng{
	namespace Resources{
		template<typename T>
		class ResourceContainer{
		public:
			std::string name{""};
			T data{};

			ResourceContainer():
				name{""},
				data{T{}}
			{

			}

			ResourceContainer(const std::string& _name):
				name{_name},
				data{T{}}
			{
				
			}

			ResourceContainer(const std::string& _name,const T& _data):
				name{_name},
				data{_data}
			{

			}
		};
	}
}
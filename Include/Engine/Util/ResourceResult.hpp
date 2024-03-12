#pragma once

#include "ResourceContainer.hpp"

#include <iostream>

namespace eng{
	namespace Resources{
		template<typename T>
		class ResourceResult{
		public:
			bool succeeded{false};
			std::shared_ptr<ResourceContainer<T>> resource{nullptr};
			std::string message{""};

			ResourceResult(const bool _succeeded,const std::string& _msg):
				succeeded{_succeeded},
				message{_msg},
				resource{nullptr}
			{

			}

			ResourceResult(const bool _succeeded,const std::string& _msg,std::shared_ptr<ResourceContainer<T>> _resource):
				succeeded{_succeeded},
				message{_msg},
				resource{_resource}
			{

			}

			void Print(){
				std::cout<<
					(std::string)(succeeded?"Success":"Error")+": "+
					message+
					(std::string)(resource!=nullptr?(std::string)(" ('"+resource->name+"')"):"")
				<<std::endl;
			}
		};
	}
}
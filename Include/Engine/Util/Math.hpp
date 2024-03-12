#pragma once

#include <cstdlib>

namespace eng{
	namespace Math{
		static float Clamp(float _value,const float _min,const float _max){
			_value=_value<_min?_min:_value;
			_value=_value>_max?_max:_value;
			return _value;
		}

		static int Clamp(int _value,const int _min,const int _max){
			_value=_value<_min?_min:_value;
			_value=_value>_max?_max:_value;
			return _value;
		}

		static float Clamp01(float _value){
			_value=_value<0.0f?0.0f:_value;
			_value=_value>1.0f?1.0f:_value;
			return _value;
		}

		static int Clamp01(int _value){
			_value=_value<0?0:_value;
			_value=_value>1?1:_value;
			return _value;
		}

		static float Clamp11(float _value){
			_value=_value<-1.0f?-1.0f:_value;
			_value=_value>1.0f?1.0f:_value;
			return _value;
		}

		static int Clamp11(int _value){
			_value=_value<-1?-1:_value;
			_value=_value>1?1:_value;
			return _value;
		}

		static int RandomRange(const int _min,const int _max){
			return rand()%(_max-_min)+_min;
		}

		static float RandomRange(const float _min,const float _max){
			const int factor{1000};
			int min=(int)(_min*factor),max=(int)(_max*factor);
			return (float)(rand()%(max-min)+min)/factor;
		}

		static float Lerp(const float _from,const float _to,const float _t){
			return _from+(_to-_from)*_t;
		}

		static float Lerp01(const float _from,const float _to,const float _t){
			return _from+(_to-_from)*Clamp01(_t);
		}
	}
}

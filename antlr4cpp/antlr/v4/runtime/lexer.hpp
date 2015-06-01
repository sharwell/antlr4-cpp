#pragma once

#include <string>

namespace antlr4 {
namespace runtime {

	std::string x;

	template<typename _String>
	class lexer_traits
	{
	public:
		typedef atn::lexer_atn_simulator interpreter_type;
		typedef int32_t token_type_type;
	};

	template<typename _String, typename _Traits>
	class basic_lexer
	{
	public:
		typedef _String string_type;
		typedef _Traits traits_type;
		typedef typename _Traits::token_type_type token_type_type;

	public:
		static const token_type_type default_mode = 0;
		static const token_type_type more = -2;
		static const token_type_type skip = -3;

	private:
		_String _input;
	};

	typedef basic_lexer<std::string, lexer_traits<std::string>> lexer;

	typedef basic_lexer<std::wstring, lexer_traits<std::wstring>> wlexer;

}
}

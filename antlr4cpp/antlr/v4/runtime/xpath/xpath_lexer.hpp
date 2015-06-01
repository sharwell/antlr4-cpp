#pragma once

#include "../token.hpp"

namespace antlr4 {
namespace runtime {
namespace xpath {

	class xpath_lexer : public wlexer
	{
	public:
		enum class xpath_token
		{
			epsilon = token::epsilon,
			eof = token::eof,
			invalid = token::invalid,
		};
	};

}
}
}

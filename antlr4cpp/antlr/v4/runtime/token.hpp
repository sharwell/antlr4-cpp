// Copyright (c) Terence Parr, Sam Harwell. Licensed under the BSD license. See LICENSE in the project root for license information.
#pragma once

#include <cstdint>

namespace antlr4 {
namespace runtime {

	class token
	{
	public:
		static const int32_t epsilon = -2;
		static const int32_t eof = -1;
		static const int32_t invalid = 0;

		static const int32_t default_channel = 0;
		static const int32_t hidden_channel = 1;
	};

}
}

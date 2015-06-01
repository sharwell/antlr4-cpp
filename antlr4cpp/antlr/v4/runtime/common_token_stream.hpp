#pragma once

#include <memory>
#include <vector>

#include "token.hpp"

namespace antlr4 {
namespace runtime {

	class token_source;

	class common_token_stream
	{
	private:
		const std::shared_ptr<token_source> _token_source;
		const int32_t _channel;

		std::vector<token> _tokens;

		size_t _index;
		bool _fetched_eof;

	public:
		common_token_stream(std::shared_ptr<token_source> token_source, int32_t channel = token::default_channel);

	public:
		std::shared_ptr<token_source> const& token_source() const
		{
			return _token_source;
		}

		size_t index() const
		{
			return _index;
		}

		size_t size() const
		{
			return _tokens.size();
		}

		int32_t mark() const
		{
			return 0;
		}

		void release(int marker) const
		{
			// no resources to release
		}

		void reset()
		{
			seek(0);
		}

		void seek(size_t index);
		void consume();

		bool sync(size_t index);
		size_t fetch(size_t count);
	};

}
}

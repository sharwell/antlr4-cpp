#pragma once

#include <memory>

namespace antlr4 {
namespace runtime {

	namespace dfa {
		class dfa_state;
	}

namespace atn {

	class grammar_atn;

	class atn_simulator abstract
	{
	public:
		static const std::shared_ptr<dfa::dfa_state> error;

	private:
		const std::shared_ptr<grammar_atn> _grammar_atn;

	protected:
		atn_simulator(std::shared_ptr<grammar_atn> const& grammar_atn)
			: _grammar_atn(grammar_atn)
		{
		}

		virtual ~atn_simulator() { }

	public:
		std::shared_ptr<grammar_atn> const& grammar_atn() const
		{
			return _grammar_atn;
		}

	public:
		virtual void reset() = 0;

	public:
		void clear_dfa();
	};

}
}
}

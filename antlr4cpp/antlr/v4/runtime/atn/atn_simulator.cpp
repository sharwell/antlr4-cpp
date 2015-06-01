#include "stdafx.h"

#include "atn_simulator.hpp"

#include "atn_configuration_set.hpp"
#include "grammar_atn.hpp"
#include "../dfa/dfa_state.hpp"

namespace antlr4 {
namespace runtime {
namespace atn {

	const std::shared_ptr<dfa::dfa_state> atn_simulator::error(std::make_shared<dfa::dfa_state>(nullptr, std::make_shared<atn_configuration_set>()));

	void atn_simulator::clear_dfa()
	{
		grammar_atn()->clear_dfa();
	}

}
}
}

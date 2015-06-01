#include "stdafx.h"

#include "dfa_state.hpp"

#include "dynamic_dfa.hpp"

#include "../atn/atn_configuration_set.hpp"

namespace antlr4 {
namespace runtime {
namespace dfa {

	using namespace antlr4::runtime::atn;

	dfa_state::dfa_state(std::shared_ptr<dynamic_dfa> const& dfa, std::shared_ptr<atn_configuration_set> const& configurations)
		: _state_number(~static_cast<size_t>(0))
		, _configurations(configurations)
		, _accept_state_information(0)
		, _min_dfa_edge(dfa->min_dfa_edge())
	{
	}

}
}
}

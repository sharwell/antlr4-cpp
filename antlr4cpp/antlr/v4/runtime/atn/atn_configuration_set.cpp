#include "stdafx.h"

#include <unordered_map>

#include <antlr/v4/runtime/atn/atn_configuration_set.hpp>
#include <antlr/v4/runtime/atn/atn_simulator.hpp>
#include <antlr/v4/runtime/atn/conflict_information.hpp>

namespace antlr4 {
namespace runtime {
namespace atn {

	class atn_configuration_set::private_data
	{
	private:
		private_data(private_data const&) = delete;
		private_data& operator= (private_data const&) = delete;

	public:
		explicit private_data()
			: cached_hash_code()
		{
		}

	public:
		std::unordered_map<int64_t, std::shared_ptr<atn_configuration>> merged_configurations;
		std::vector<std::shared_ptr<atn_configuration>> unmerged_configurations;
		std::vector<std::shared_ptr<atn_configuration>> configurations;

		int32_t unique_alternative;
		std::unique_ptr<atn::conflict_information> conflict_information;
		bool has_semantic_context;
		bool dips_into_outer_context;
		bool outermost;
		bool read_only;

		size_t cached_hash_code;
	};

	atn_configuration_set::atn_configuration_set()
		: data(std::make_unique<private_data>())
	{
	}

	atn_configuration_set::~atn_configuration_set()
	{
	}

	bool atn_configuration_set::read_only() const
	{
		return data->read_only;
	}

	bool atn_configuration_set::outermost() const
	{
		return data->outermost;
	}

	int32_t atn_configuration_set::unique_alternative() const
	{
		throw std::runtime_error("not implemented");
	}

	bool atn_configuration_set::has_semantic_context() const
	{
		throw std::runtime_error("not implemented");
	}

	std::unique_ptr<conflict_information> const& atn_configuration_set::conflict_information() const
	{
		throw std::runtime_error("not implemented");
	}

	bool atn_configuration_set::dips_into_outer_context() const
	{
		throw std::runtime_error("not implemented");
	}

	std::vector<bool> atn_configuration_set::represented_alternatives() const
	{
		throw std::runtime_error("not implemented");
	}

	std::vector<std::shared_ptr<atn_state>> atn_configuration_set::states() const
	{
		throw std::runtime_error("not implemented");
	}

	std::vector<std::shared_ptr<atn_configuration>> const& atn_configuration_set::configurations() const
	{
		throw std::runtime_error("not implemented");
	}

	bool atn_configuration_set::contains(std::shared_ptr<atn_configuration> const& configuration) const
	{
		throw std::runtime_error("not implemented");
	}

	bool atn_configuration_set::add(std::shared_ptr<atn_configuration> const& configuration, prediction_context_cache& context_cache)
	{
		throw std::runtime_error("not implemented");
	}

	void atn_configuration_set::optimize(std::shared_ptr<atn_simulator> const& interpreter)
	{
		throw std::runtime_error("not implemented");
	}

	bool operator==(antlr4::runtime::atn::atn_configuration_set const& x, antlr4::runtime::atn::atn_configuration_set const& y)
	{
		if (&x ==&y)
		{
			return true;
		}

		if (x.outermost() != y.outermost())
		{
			return false;
		}

		if (!(x.conflict_information() == y.conflict_information()))
		{
			return false;
		}

		throw std::runtime_error("equality comparison of std::vector<std::shared_ptr<...>> is not yet implemented");
	}

}
}
}

namespace std {

	using namespace antlr4::runtime::atn;

	size_t hash<atn_configuration_set>::operator()(atn_configuration_set const& configuration_set) const
	{
		if (configuration_set.read_only()&& configuration_set.data->cached_hash_code)
		{
			return configuration_set.data->cached_hash_code;
		}

		size_t hash = 1;
		hash = 5 * hash ^ (configuration_set.outermost() ? 1 : 0);
		throw std::runtime_error("hash = 5 * hash ^ hasher(configuration_set.configurations());");

		if (configuration_set.read_only())
		{
			configuration_set.data->cached_hash_code = hash;
		}

		return hash;
	}

}

// Copyright Abel Sinkovics (abel@sinkovics.hu) 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/eval_multi_let.hpp>
#include <mpllibs/metamonad/pair.hpp>
#include <mpllibs/metamonad/syntax.hpp>

#include <boost/test/unit_test.hpp>

#include <boost/mpl/plus.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/assert.hpp>

#include "common.hpp"


BOOST_AUTO_TEST_CASE(test_eval_multi_let)
{
  using boost::mpl::equal_to;
  using boost::mpl::plus;
  using boost::mpl::map;
  
  using mpllibs::metamonad::eval_multi_let;
  using mpllibs::metamonad::syntax;
  using mpllibs::metamonad::pair;

  // test_evaluation_of_expression
  BOOST_MPL_ASSERT((
    equal_to<
      int13,
      eval_multi_let<
        map<pair<x, syntax<int11> > >, syntax<plus<int2, x> >
      >::type
    >
  ));
}




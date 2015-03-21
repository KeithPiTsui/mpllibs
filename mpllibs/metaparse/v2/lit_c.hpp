#ifndef MPLLIBS_METAPARSE_V2_LIT_C_HPP
#define MPLLIBS_METAPARSE_V2_LIT_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <boost/mpl/char.hpp>

#include <mpllibs/metaparse/v2/error/literal_expected.hpp>
#include <mpllibs/metaparse/v2/accept_when.hpp>
#include <mpllibs/metaparse/v2/one_char.hpp>

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/char.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <char C>
      struct lit_c :
        accept_when<
          one_char,
          typename boost::mpl::lambda<
            boost::mpl::equal_to<boost::mpl::_1, boost::mpl::char_<C> >
          >::type,
          error::literal_expected<C>
        >
      {};
    }
  }
}

#endif

#ifndef MPLLIBS_METAMONAD_IMPL_LAMBDA_HPP
#define MPLLIBS_METAMONAD_IMPL_LAMBDA_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/let.hpp>
#include <mpllibs/metamonad/syntax.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/eval_syntax.hpp>
#include <mpllibs/metamonad/unused_arg.hpp>
#include <mpllibs/metamonad/metafunction.hpp>

#include <boost/mpl/apply.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/contains.hpp>

#include <boost/type_traits.hpp>

#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/tuple/eat.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace impl
    {
      struct lambda_impl_step : tmp_value<lambda_impl_step>
      {
        MPLLIBS_METAFUNCTION(apply, (State)(T))
        ((
          boost::mpl::pair<
            typename boost::mpl::pop_front<
              typename boost::mpl::first<State>::type
            >::type,
            typename boost::mpl::eval_if<
              typename boost::is_same<
                typename boost::mpl::front<
                  typename boost::mpl::first<State>::type
                >::type,
                _
              >::type,
              typename boost::mpl::second<State>::type,
              let<
                typename boost::mpl::front<
                  typename boost::mpl::first<State>::type
                >::type,
                syntax<T>,
                typename boost::mpl::second<State>::type
              >
            >::type
          >
        ));
      };

      template <class State>
      struct lambda_impl :
        boost::mpl::if_<
          typename boost::mpl::empty<
            typename boost::mpl::first<State>::type
          >::type,
          eval_syntax<boost::mpl::second<State> >,
          tmp_value<lambda_impl<State> >
        >::type
      {
        template <
          BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(
            BOOST_MPL_LIMIT_METAFUNCTION_ARITY,
            class T,
            boost::mpl::na
          )
        >
        struct apply :
          lambda_impl<
            typename boost::mpl::fold<
              boost::mpl::vector<
                BOOST_PP_ENUM_PARAMS(BOOST_MPL_LIMIT_METAFUNCTION_ARITY, T)
              >,
              State,
              lambda_impl_step
            >::type
          >
        {};
      };

      template <class A, class E1, class State>
      struct
        let_impl<A, E1, impl::lambda_impl<State> > :
          impl::lambda_impl<
            boost::mpl::pair<
              typename boost::mpl::first<State>::type,
              typename boost::mpl::eval_if<
                typename boost::mpl::contains<
                  typename boost::mpl::first<State>::type,
                  A
                >::type,
                boost::mpl::second<State>,
                let_in_syntax<A, E1, typename boost::mpl::second<State>::type>
              >::type
            >
          >
      {};
    }
  }
}

#endif


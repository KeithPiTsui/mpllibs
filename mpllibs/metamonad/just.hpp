#ifndef MPLLIBS_METAMONAD_JUST_HPP
#define MPLLIBS_METAMONAD_JUST_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>
#include <mpllibs/metamonad/get_data.hpp>
#include <mpllibs/metamonad/tmp_value.hpp>
#include <mpllibs/metamonad/metafunction.hpp>
#include <mpllibs/metamonad/returns.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

#include <boost/mpl/equal_to.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metamonad
  {
    struct just_tag : tmp_tag<just_tag> {};
    
    template <class T>
    struct just : tmp_value<just<T>, just_tag>
    {
      typedef T data;
    };
    
    template <>
    struct get_data_impl<just_tag>
    {
      MPLLIBS_METAFUNCTION(apply, (T)) ((returns<typename T::data>));
    };
  }
}

namespace boost
{
  namespace mpl
  {
    template <class A, class B>
    struct equal_to_impl;

    template <>
    struct
      equal_to_impl<
        mpllibs::metamonad::just_tag,
        mpllibs::metamonad::just_tag
      >
    {
      MPLLIBS_METAFUNCTION(apply, (A)(B))
      ((
        equal_to<
          typename mpllibs::metamonad::get_data<A>::type,
          typename mpllibs::metamonad::get_data<B>::type
        >
      ));
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::just,
  "just"
)

#endif


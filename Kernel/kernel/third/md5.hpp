#pragma once

#if defined M_compiler_msvc
#pragma warning(push, 0)
#endif
#if defined M_compiler_clang
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#endif

#include "third/md5/md5.h"

#if defined M_compiler_msvc
#pragma warning(pop)
#endif
#if defined M_compiler_clang
#pragma clang diagnostic pop
#endif

namespace Twinning::Kernel::Third::md5 {

	using MD5 = ::MD5;

	using byte = ::byte;

}

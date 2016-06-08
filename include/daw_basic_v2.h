// The MIT License (MIT)
//
// Copyright (c) 2013-2015 Darrell Wright
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files( the "Software" ), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <daw/char_range/daw_char_range.h>
#include <daw/asteroid/asteroid.h>
#include <memory>

namespace daw {
	namespace basic {
		inline namespace v2 {
			class Basic {
				std::shared_ptr<daw::asteroid::ast_node_scope> m_ast;							
			public:
				Basic( );
				~Basic( );
				Basic( Basic const & ) = default;
				Basic( Basic && ) = default;
				Basic & operator=( Basic const & ) = default;
				Basic & operator=( Basic && ) = default;
				
				void parse_line( daw::range::CharRange line_str ); 
				void parse_range( daw::range::CharRange basic_file );  
			};	// class Basic
		}	// namespace v2
	}	// namespace basic
}	// namespace daw


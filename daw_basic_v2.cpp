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

#include <boost/optional.hpp>
#include <boost/utility/string_ref.hpp>
#include <unordered_map>
#include <daw/char_range/daw_char_range.h>
#include <daw/daw_algorithm.h>
#include <daw/daw_traits.h>
#include "daw_basic_v2.h"

namespace daw {
	namespace basic {
		inline namespace v2 {
			namespace {
				enum class basic_keywords: uint8_t { NEW, CLR, DELETE, DIM, FUNCTION, SUB, LET, STOP, CONT, GOTO, GOSUB, RETURN, PRINT, QUIT, EXIT, END, REM, LIST, RUN, VARS, FUNCTIONS, KEYWORDS, THEN, IF };

				auto get_keyword( basic_keywords keyword ) {
					switch( keyword ) {
					case basic_keywords::NEW: return "NEW";
					case basic_keywords::CLR: return "CLR";
					case basic_keywords::DELETE: return "DELETE";
					case basic_keywords::DIM: return "DIM";
					case basic_keywords::FUNCTION: return "FUNCTION";
					case basic_keywords::SUB: return "SUB";
					case basic_keywords::LET: return "LET";
					case basic_keywords::STOP: return "STOP";
					case basic_keywords::CONT: return "CONT";
					case basic_keywords::GOTO: return "GOTO";
					case basic_keywords::GOSUB: return "GOSUB";
					case basic_keywords::RETURN: return "RETURN";
					case basic_keywords::PRINT: return "PRINT";
					case basic_keywords::QUIT: return "QUIT";
					case basic_keywords::EXIT: return "EXIT";
					case basic_keywords::END: return "END";
					case basic_keywords::REM: return "REM";
					case basic_keywords::LIST: return "LIST";
					case basic_keywords::RUN: return "RUN";
					case basic_keywords::VARS: return "VARS";
					case basic_keywords::FUNCTIONS: return "FUNCTIONS";
					case basic_keywords::KEYWORDS: return "KEYWORDS";
					case basic_keywords::THEN: return "THEN";
					case basic_keywords::IF: return "IF";
					}
					throw std::runtime_error( "Unknown keyword enum specified" );
				}

				auto const & get_keyword( boost::string_ref keyword ) {
					static std::unordered_map<std::string, basic_keywords> keywords = {
						{ "NEW", basic_keywords::NEW },
						{ "CLR", basic_keywords::CLR },
						{ "DELETE", basic_keywords::DELETE },
						{ "DIM", basic_keywords::DIM },
						{ "FUNCTION", basic_keywords::FUNCTION },
						{ "SUB", basic_keywords::SUB },
						{ "LET", basic_keywords::LET },
						{ "STOP", basic_keywords::STOP },
						{ "CONT", basic_keywords::CONT },
						{ "GOTO", basic_keywords::GOTO },
						{ "GOSUB", basic_keywords::GOSUB },
						{ "RETURN", basic_keywords::RETURN },
						{ "PRINT", basic_keywords::PRINT },
						{ "QUIT", basic_keywords::QUIT },
						{ "EXIT", basic_keywords::EXIT },
						{ "END", basic_keywords::END },
						{ "REM", basic_keywords::REM },
						{ "LIST", basic_keywords::LIST },
						{ "RUN", basic_keywords::RUN },
						{ "VARS", basic_keywords::VARS },
						{ "FUNCTIONS", basic_keywords::FUNCTIONS },
						{ "KEYWORDS", basic_keywords::KEYWORDS },
						{ "THEN", basic_keywords::THEN },
						{ "IF", basic_keywords::IF }
					};
					return keywords[keyword.to_string( )];
				}

				struct keyword_arguments {
					keyword_arguments( boost::string_ref arguments_string ) { }

					~keyword_arguments( ) = default;
				};	// struct keyword_arguments

				struct basic_line {
					boost::optional<uintmax_t> label;
					basic_keywords keyword;
					keyword_arguments arguments;
					
					basic_line( ) = delete;
					basic_line( boost::optional<uintmax_t> lbl, basic_keywords Keyword, keyword_arguments args ): 
						label{ lbl }, 
						keyword{ std::move( Keyword ) }, 
						arguments{ std::move( args ) } { }

					~basic_line( ) = default;
				};	// struct basic_line

			}	// namespace anonymous
			Basic::Basic( ):
				m_ast { std::make_shared<daw::asteroid::ast_node_scope>( ) } {

			}

			Basic::~Basic( ) { }

			void Basic::parse_line( daw::range::CharRange line_str ) {

			}

			void Basic::parse_range( daw::range::CharRange basic_file ) {
				auto end = basic_file.end( );
				auto last_pos = basic_file.begin( );
				auto find_next_pos = [&]( ) {
					return daw::algorithm::find_first_of( last_pos, end, []( auto ch ) {
						return ch == '\n';
					} );
				};
				auto pos = find_next_pos( );
				while( pos != end ) {
					parse_line( daw::range::CharRange { last_pos, pos } );
					last_pos = pos;
					pos = find_next_pos( );
				}
			}
		}	// namespace v2
	}	// namespace basic
}	// namespace daw


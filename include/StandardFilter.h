/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "TokenFilter.h"

namespace Lucene
{
	/// Normalizes tokens extracted with {@link StandardTokenizer}.
	class LPPAPI StandardFilter : public TokenFilter
	{
	public:
		/// Construct filtering input.
		StandardFilter(TokenStreamPtr input);
		virtual ~StandardFilter();
		
		LUCENE_CLASS(StandardFilter);
	
	protected:
		TypeAttributePtr typeAtt;
		TermAttributePtr termAtt;
	
	protected:
		static String& APOSTROPHE_TYPE();
		static String& ACRONYM_TYPE();
	
	public:
		/// Returns the next token in the stream, or null at EOS.
		///
		/// Removes <tt>'s</tt> from the end of words.
		/// Removes dots from acronyms.
		virtual bool incrementToken();
	};
}
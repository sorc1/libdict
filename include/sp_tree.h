/*
 * libdict -- splay tree interface.
 *
 * Copyright (c) 2001-2011, Farooq Mela
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by Farooq Mela.
 * 4. Neither the name Farooq Mela nor the names of contributors may be used to
 *    endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY FAROOQ MELA ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL FAROOQ MELA BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SP_TREE_H_
#define _SP_TREE_H_

#include "dict.h"

BEGIN_DECL

typedef struct sp_tree sp_tree;

sp_tree*	sp_tree_new(dict_compare_func cmp_func,
			    dict_delete_func del_func);
dict*		sp_dict_new(dict_compare_func cmp_func,
			    dict_delete_func del_func);
size_t		sp_tree_free(sp_tree* tree);
sp_tree*	sp_tree_clone(sp_tree* tree,
			      dict_key_datum_clone_func clone_func);

void**		sp_tree_insert(sp_tree* tree, void* key, bool* inserted);
void*		sp_tree_search(sp_tree* tree, const void* key);
bool		sp_tree_remove(sp_tree* tree, const void* key);
size_t		sp_tree_clear(sp_tree* tree);
size_t		sp_tree_traverse(sp_tree* tree, dict_visit_func visit);
size_t		sp_tree_count(const sp_tree* tree);
size_t		sp_tree_height(const sp_tree* tree);
size_t		sp_tree_mheight(const sp_tree* tree);
size_t		sp_tree_pathlen(const sp_tree* tree);
const void*	sp_tree_min(const sp_tree* tree);
const void*	sp_tree_max(const sp_tree* tree);
bool		sp_tree_verify(const sp_tree* tree);

typedef struct sp_itor sp_itor;

sp_itor*	sp_itor_new(sp_tree* tree);
dict_itor*	sp_dict_itor_new(sp_tree* tree);
void		sp_itor_free(sp_itor* tree);

bool		sp_itor_valid(const sp_itor* itor);
void		sp_itor_invalidate(sp_itor* itor);
bool		sp_itor_next(sp_itor* itor);
bool		sp_itor_prev(sp_itor* itor);
bool		sp_itor_nextn(sp_itor* itor, size_t count);
bool		sp_itor_prevn(sp_itor* itor, size_t count);
bool		sp_itor_first(sp_itor* itor);
bool		sp_itor_last(sp_itor* itor);
bool		sp_itor_search(sp_itor* itor, const void* key);
const void*	sp_itor_key(const sp_itor* itor);
void**		sp_itor_data(sp_itor* itor);
bool		sp_itor_remove(sp_itor* itor);

END_DECL

#endif /* !_SP_TREE_H_ */

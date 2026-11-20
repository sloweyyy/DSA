is_symmetric(Root) -> mirror(Root, Root).

mirror(null, null) -> true;
mirror(#tree_node{val = V, left = AL, right = AR}, #tree_node{val = V, left = BL, right = BR}) -> mirror(AL, BR) andalso mirror(AR, BL);
mirror(_, _) -> false.

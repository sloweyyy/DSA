product_of_numbers_init_() ->
    put(product_count, 0),
    put({product_prefix, 0}, 1),
    ok.

product_of_numbers_add(0) ->
    put(product_count, 0),
    ok;
product_of_numbers_add(Num) ->
    Count = get(product_count),
    put({product_prefix, Count + 1}, get({product_prefix, Count}) * Num),
    put(product_count, Count + 1),
    ok.

product_of_numbers_get_product(K) ->
    Count = get(product_count),
    case K > Count of
        true -> 0;
        false ->
            get({product_prefix, Count}) div
                get({product_prefix, Count - K})
    end.

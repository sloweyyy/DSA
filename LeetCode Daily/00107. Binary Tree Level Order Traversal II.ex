defmodule Solution do
    def level_order_bottom(nil), do: []
    def level_order_bottom(root), do: levels([root], [])

    defp levels([], result), do: result
    defp levels(nodes, result) do
        values = Enum.map(nodes, &(&1.val))
        children = Enum.flat_map(nodes, fn node -> [node.left, node.right] end) |> Enum.reject(&is_nil/1)
        levels(children, [values | result])
    end
end

defmodule Solution do
    def sum_numbers(root), do: visit(root, 0)
    defp visit(nil, _), do: 0
    defp visit(%TreeNode{left: nil, right: nil, val: digit}, prefix), do: prefix * 10 + digit
    defp visit(node, prefix) do
        value = prefix * 10 + node.val
        visit(node.left, value) + visit(node.right, value)
    end
end

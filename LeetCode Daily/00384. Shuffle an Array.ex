defmodule Solution do def init_(nums), do: Process.put({__MODULE__, :original}, nums); def reset(), do: Process.get({__MODULE__, :original}); def shuffle(), do: Enum.shuffle(reset()) end

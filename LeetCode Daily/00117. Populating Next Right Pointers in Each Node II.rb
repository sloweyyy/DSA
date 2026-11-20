def connect(root)
    level = root
    dummy = Node.new(0)
    while level
        dummy.next = nil
        tail = dummy
        current = level
        while current
            if current.left
                tail.next = current.left
                tail = tail.next
            end
            if current.right
                tail.next = current.right
                tail = tail.next
            end
            current = current.next
        end
        level = dummy.next
    end
    root
end

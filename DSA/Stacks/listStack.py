class Stack:
    def __init__(self):
        self.stack = []

    def isEmpty(self):
        return len(self.stack) == 0

    def push(self, data):
        self.stack.append(data)

    def popp(self):
        if self.isEmpty():
            return "Stack is empty"
        self.stack.pop()

    def top(self):
        if self.isEmpty():
            return "Stack is empty"
        return self.stack[-1]

    def size(self):
        return len(self.stack)

    def display(self):
        for i in self.stack:
            print(i, end=" ")
        print("\n")


s = Stack()
print(s.isEmpty())
s.push(2)
s.push(1)
s.display()
s.push(3)
s.push(4)
s.push(5)
s.display()
s.popp()
s.display()
print(s.top())
print(s.isEmpty())

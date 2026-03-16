from SLList import SLList
import unittest

class testSLList(unittest.TestCase):

    def test_init(self):
        l = SLList()
        self.assertEqual(l._head.value, -1)
        self.assertEqual(l._head.next, None)
        self.assertTrue(l._head, l._tail)

    def test_addFirst(self):
        l = SLList()
        for i in range(1, 4):
            l.addFirst(i)
        self.assertEqual(l._head.next.value, 3)
        self.assertEqual(l._head.next.next.value, 2)
        self.assertEqual(l._head.next.next.next.value, 1)

    def test_addLast(self):
        l = SLList()
        for i in range(1, 4):
            l.addLast(4 - i)
        self.assertEqual(l._head.next.value, 3)
        self.assertEqual(l._head.next.next.value, 2)
        self.assertEqual(l._head.next.next.next.value, 1)

    def test_size(self):
        l = SLList()
        for i in range(1, 4):
            l.addLast(i)
        self.assertEqual(l.size(), 3)


if __name__ == '__main__':
    unittest.main()
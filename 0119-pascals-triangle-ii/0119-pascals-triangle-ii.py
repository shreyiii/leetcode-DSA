class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [1]

        for r in range(1, rowIndex + 1):
            row.append(row[-1] * (rowIndex - r + 1) // r)

        return row
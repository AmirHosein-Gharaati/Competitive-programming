const subsetsWith = (
  n: number,
  set: number[],
  res: number[][],
  c: number[] = [],
  idx = 0,
  total = n
) => {
  if (n === 0) {
    if (c.length === total) {
      res.push(c.slice());
    }
    return;
  }
  if (idx >= set.length) return;

  c.push(set[idx]);
  subsetsWith(n - 1, set, res, c, idx + 1, total);

  c.pop();
  subsetsWith(n, set, res, c, idx + 1, total);
};

function subsets(nums: number[]): number[][] {
  const result: number[][] = [[]];

  for (let i = 1; i <= nums.length; i++) {
    subsetsWith(i, nums, result);
  }

  return result;
}

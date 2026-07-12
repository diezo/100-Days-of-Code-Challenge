# Auction Sniper Detection

An online auction platform records every bid placed during an auction.

Each bid is represented by:

- `timestamp` — the time (in seconds) when the bid was placed.
- `bidderId` — the unique ID of the bidder.

The bids are given in **non-decreasing order of timestamp**.

The platform wants to detect suspicious bidding activity (auction sniping).

For every bid, consider all bids placed during the last **M** seconds (inclusive). That is, for a bid occurring at time `T`, the window contains every bid whose timestamp satisfies:

```
timestamp >= T - M
timestamp <= T
```

Within this time window:

1. Count how many bids each bidder has placed.
2. A bidder is considered **suspicious** if they have placed at least **K** bids within the current window.

For every bid, determine:

- Whether the bidder who placed the current bid is suspicious.
- The bidder with the **smallest bidderId** among all suspicious bidders in the current window.

If no bidder is suspicious in the current window, output `-1`.

---

## Input Format

```
N M K
timestamp1 bidderId1
timestamp2 bidderId2
...
timestampN bidderIdN
```

where:

- `N` = number of bids
- `M` = sliding window size (in seconds)
- `K` = minimum number of bids required for a bidder to be considered suspicious

---

## Output Format

For every bid, output one line containing:

```
isCurrentBidderSuspicious smallestSuspiciousBidder
```

where:

- `isCurrentBidderSuspicious`
  - `1` if the current bidder has placed at least `K` bids in the current window.
  - `0` otherwise.

- `smallestSuspiciousBidder`
  - The smallest `bidderId` whose frequency in the current window is at least `K`.
  - `-1` if no bidder is suspicious.

---

## Constraints

```
1 ≤ N ≤ 2 × 10^5
0 ≤ timestamp ≤ 10^9
1 ≤ bidderId ≤ 10^9
1 ≤ M ≤ 10^9
1 ≤ K ≤ N
```

- Bids are sorted in non-decreasing order of `timestamp`.

---

## Example

### Input

```
9 5 3
1 101
2 205
3 101
5 101
6 205
7 101
8 310
10 205
11 205
```

### Output

```
0 -1
0 -1
0 -1
1 101
0 101
1 101
0 101
1 205
1 205
```

---

## Explanation

For the bid `(7, 101)`:

Current window contains all bids with timestamps in the range `[2, 7]`.

The bids in the window are:

```
(2,205)
(3,101)
(5,101)
(6,205)
(7,101)
```

Their frequencies are:

```
101 → 3
205 → 2
```

Since bidder `101` appears at least `K = 3` times:

- The current bidder is suspicious.
- The smallest suspicious bidder is `101`.

Hence the output for this bid is:

```
1 101
```
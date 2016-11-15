module Main where

solve :: String -> Int -> Int
solve ('A':xs) d = max d (solve xs 1)
solve ('E':xs) d = max d (solve xs 1)
solve ('I':xs) d = max d (solve xs 1)
solve ('O':xs) d = max d (solve xs 1)
solve ('U':xs) d = max d (solve xs 1)
solve ('Y':xs) d = max d (solve xs 1)
solve (_:xs) d = solve xs (d + 1)
solve [] d = d

main :: IO ()
main = do
  s <- getLine
  print $ solve s 1

module Main where

readLeftAndRight :: Int -> IO [(Int, Int)]
readLeftAndRight 0 = return []
readLeftAndRight n = do
  l <- read :: IO Int
  r <- read :: IO Int
  mapM ((:) (l, r)) (readLeftAndRight (n - 1))

main :: IO ()
main = do
  n <- readLn :: IO Int
  print n

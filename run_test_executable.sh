#! /bin/sh

# Check if at least one test name is provided
if [ "$#" -eq 0 ]; then
  echo "Usage: $0 <test_name1> [<test_name2> ...]"
  exit 1
fi

# Loop through each provided test name
for test_name in "$@"; do
  # Build the path to the test executable
  test_executable="./build/tests/$test_name"

  # Check if the test executable exists
  if [ -x "$test_executable" ]; then
    # Run the test executable
    echo "Running test: $test_name"
    "$test_executable"
    echo "---------------------"
  else
    echo "Error: Test executable '$test_name' not found."
    exit 1
  fi
done

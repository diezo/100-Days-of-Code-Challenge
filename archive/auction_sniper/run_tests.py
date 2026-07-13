import subprocess
import sys

NUM_TESTS = 7
JAVA_FILE = "Main.java"
CLASS_NAME = "Main"
TEST_DIR = "testcases"

# Compile
compile_result = subprocess.run(
    ["javac", JAVA_FILE],
    capture_output=True,
    text=True
)

if compile_result.returncode != 0:
    print("❌ Compilation Failed\n")
    print(compile_result.stderr)
    sys.exit(1)

passed = 0

for i in range(1, NUM_TESTS + 1):

    input_file = f"{TEST_DIR}/test{i}.txt"
    expected_file = f"{TEST_DIR}/expected{i}.txt"

    with open(input_file, "r") as fin:
        result = subprocess.run(
            ["java", CLASS_NAME],
            stdin=fin,
            capture_output=True,
            text=True
        )

    actual = result.stdout.strip()
    error = result.stderr.strip()

    # Runtime Error
    if result.returncode != 0:
        print(f"❌ Test {i} Crashed\n")

        print("Java Error:")
        print("=" * 40)
        print(error)
        print("=" * 40)

        sys.exit(1)

    with open(expected_file, "r") as f:
        expected = f.read().strip()

    if actual == expected:
        print(f"✅ Test {i} Passed")
        passed += 1
    else:
        print(f"❌ Test {i} Failed\n")

        print("Your Output:")
        print("=" * 40)
        print(actual if actual else "<No Output>")
        print("=" * 40)

        print("\nExpected Output:")
        print("=" * 40)
        print(expected)
        print("=" * 40)

        sys.exit(1)

print(f"\n🎉 All {passed}/{NUM_TESTS} Tests Passed!")
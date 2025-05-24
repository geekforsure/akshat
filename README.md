
# Spam Detection System (C Project)

This project is a simple spam detection system written in C. It identifies unwanted emails by checking for specific spam-related keywords. A hash table is used for storing keywords, ensuring fast lookups and efficient memory usage.

---

## 🚀 Features

- Hash table for keyword storage and fast lookup
- Basic email parsing and cleaning
- Classification of emails as "spam" or "safe"
- Lightweight and easy to understand

---

## 📂 Project Structure

```
/spam-detection-c
│
├── main.c             # Entry point of the program
├── hash_table.c       # Hash table implementation
├── hash_table.h       # Header file for hash table
├── spam_filter.c      # Spam detection logic
├── spam_filter.h      # Header file for spam logic
├── test_emails/       # Sample emails for testing
└── README.md          # Project documentation
```

---

## 🔧 How to Compile and Run

1. Clone the repository:

```bash
git clone https://github.com/username/spam-detection-c
cd spam-detection-c
```

2. Compile the program:

```bash
gcc main.c hash_table.c spam_filter.c -o spam_detector
```

3. Run the program:

```bash
./spam_detector
```

---

## 🧪 Sample Usage

```
Enter email content:
You have won a free prize! Click here now!
Result: SPAM detected
```

---

## 📌 Important Commits

- `a1b2c3d` – Initial hash table implementation
- `d4e5f6g` – Added spam detection logic


---

## 📝 Author

Created by as a college project.

---

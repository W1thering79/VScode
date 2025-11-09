import React, { useState } from "react";
import { getFirestore, collection, addDoc } from "firebase/firestore";

function RsvpPage() {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [attending, setAttending] = useState("yes");
  const [guests, setGuests] = useState(1);
  const [submitted, setSubmitted] = useState(false);
  const [error, setError] = useState("");

  const db = getFirestore();

  const handleSubmit = async (e) => {
    e.preventDefault();
    setError("");

    if (!name || !email) {
      setError("Please fill out your name and email.");
      return;
    }

    const rsvpData = {
      name: name,
      email: email,
      attending: attending,
      guestCount: attending === "yes" ? parseInt(guests, 10) : 0,
      timestamp: new Date(),
    };

    try {
      console.log("RSVP Submitted:", rsvpData);

      const docRef = await addDoc(collection(db, "rsvps"), rsvpData);
      console.log("RSVP saved with ID: ", docRef.id);

      setSubmitted(true);

    } catch (err) {
      console.error("Error submitting RSVP:", err);
      setError("There was an error submitting your RSVP. Please try again.");
    }
  };

  if (submitted) {
    return (
      <div style={styles.container}>
        <h2 style={styles.header}>Thank You!</h2>
        <p>Your RSVP has been received. We look forward to seeing you!</p>
      </div>
    );
  }

  return (
    <div style={styles.container}>
      <h2 style={styles.header}>RSVP for Our Event</h2>
      <form onSubmit={handleSubmit} style={styles.form}>
        
        <label style={styles.label}>
          Your Name:
          <input
            type="text"
            value={name}
            onChange={(e) => setName(e.target.value)}
            style={styles.input}
            required
          />
        </label>

        <label style={styles.label}>
          Your Email:
          <input
            type="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            style={styles.input}
            required
          />
        </label>

        <fieldset style={styles.fieldset}>
          <legend>Will you be attending?</legend>
          <label style={styles.radioLabel}>
            <input
              type="radio"
              value="yes"
              checked={attending === "yes"}
              onChange={(e) => {
                setAttending(e.target.value);
                setGuests(1);
              }}
            />
            Yes, I'll be there!
          </label>
          <label style={styles.radioLabel}>
            <input
              type="radio"
              value="no"
              checked={attending === "no"}
              onChange={(e) => {
                setAttending(e.target.value);
                setGuests(0);
              }}
            />
            No, I'm not able to make it.
          </label>
        </fieldset>

        {attending === "yes" && (
          <label style={styles.label}>
            Number of Guests (including yourself):
            <input
              type="number"
              value={guests}
              onChange={(e) => setGuests(e.target.value)}
              min="1"
              max="10"
              style={styles.input}
            />
          </label>
        )}

        {error && <p style={styles.error}>{error}</p>}

        <button type="submit" style={styles.button}>
          Submit RSVP
        </button>
      </form>
    </div>
  );
}

const styles = {
  container: {
    maxWidth: "500px",
    margin: "40px auto",
    padding: "20px",
    border: "1px solid #ddd",
    borderRadius: "8px",
    boxShadow: "0 2px 5px rgba(0,0,0,0.1)",
    fontFamily: "Arial, sans-serif",
  },
  header: {
    textAlign: "center",
    marginBottom: "20px",
  },
  form: {
    display: "flex",
    flexDirection: "column",
    gap: "15px",
  },
  label: {
    display: "flex",
    flexDirection: "column",
    fontWeight: "bold",
  },
  input: {
    padding: "8px",
    marginTop: "5px",
    border: "1px solid #ccc",
    borderRadius: "4px",
    fontSize: "16px",
  },
  fieldset: {
    border: "none",
    padding: 0,
    margin: 0,
  },
  radioLabel: {
    display: "flex",
    alignItems: "center",
    gap: "8px",
    fontWeight: "normal",
    marginBottom: "5px",
  },
  error: {
    color: "red",
    textAlign: "center",
  },
  button: {
    padding: "12px",
    backgroundColor: "#007bff",
    color: "white",
    border: "none",
    borderRadius: "4px",
    fontSize: "16px",
    cursor: "pointer",
    marginTop: "10px",
  },
};

export default RsvpPage;
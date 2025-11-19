import Navbar from "./components/Navbar";
import FeaturedItem from "./components/FeaturedItem";
import Dashboard from "./components/Dashboard";
import React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import MapPage from "./pages/MapPage";
import ActivityPage from "./pages/ActivityPage";
import RsvpPage from "./pages/RsvpPage";
import LoginPage from "./pages/LoginPage";
import RegisterPage from "./pages/RegisterPage";
import LandingPage from "./pages/LandingPage";
import { AuthProvider } from "./contexts/authContext";
import PrivateRoute from "./components/PrivateRoute";

function App() {
  return (
    <AuthProvider>
      <Router>
        <Routes>
          <Route path="/" element={<LandingPage />} />
          <Route
            path="/home"
            element={
              <PrivateRoute>
                <>
                  <Navbar />
                  <FeaturedItem />
                  <Dashboard />
                </>
              </PrivateRoute>
            }
          />
          <Route
            path="/map"
            element={
              <PrivateRoute>
                <Navbar />
                <MapPage />
              </PrivateRoute>
            }
          />
          <Route
            path="/activity"
            element={
              <PrivateRoute>
                <Navbar />
                <ActivityPage />
              </PrivateRoute>
            }
          />
          <Route
            path="/rsvp"
            element={
              <PrivateRoute>
                <Navbar />
                <RsvpPage />
              </PrivateRoute>
            }
          />
          <Route path="/login" element={<LoginPage />} />
          <Route path="/register" element={<RegisterPage />} />
        </Routes>
      </Router>
    </AuthProvider>
  );
}

export default App;

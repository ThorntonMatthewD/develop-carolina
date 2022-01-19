import './App.css';
import * as React from 'react';

//Icons
import Email from '@mui/icons-material/Email'
import Lock from '@mui/icons-material/Lock';

//Components
import Box from '@mui/material/Box'
import Button from '@mui/material/Button';
import Grid from '@mui/material/Grid';
import CssBaseline from '@mui/material/CssBaseline';
import InputAdornment from '@mui/material/InputAdornment'
import TextField from '@mui/material/TextField';
import Typography from '@mui/material/Typography';
import { createTheme, ThemeProvider } from '@mui/material/styles';
import { Alert, Collapse, Container } from '@mui/material';


const theme = createTheme({
  palette: {
    primary: {
      light: '#757ce8',
      main: '#6200EE',
      dark: '#002884',
      contrastText: '#fff',
    }
  }
});


function App() {

  const [forgotOpen, setForgotOpen] = React.useState(false);

  return (
    <div className="App">
      <ThemeProvider theme={theme}>
        <Container component="main" maxWidth="xs">
          <CssBaseline />
          <Grid
            container
            spacing={0}
            direction="column"
            alignItems="center"
            justifyContent="center"
            style={{ minHeight: '90vh' }}
          >
              <Typography component="h1" variant="h3">
                Welcome!
              </Typography>
              <Box component="form" noValidate sx={{ mt: 3 }}>
                <TextField
                  margin="normal"
                  fullWidth
                  id="email"
                  name="email"
                  autoComplete="email"
                  placeholder="Email"
                  autoFocus
                  InputProps={{
                    startAdornment: (
                      <InputAdornment position="start">
                        <Email />
                      </InputAdornment>
                    ),
                  }}
                />
                <TextField
                  margin="normal"
                  fullWidth
                  name="password"
                  type="password"
                  id="password"
                  autoComplete="password"
                  placeholder="Password"
                  InputProps={{
                    startAdornment: (
                      <InputAdornment position="start">
                      <Lock />
                      </InputAdornment>
                    ),
                  }}
                />
                <Button
                  fullWidth
                  variant="contained"
                  sx={{ mt: 1, mb: 0 }}
                >
                  SIGN IN
                </Button>
                <Collapse in={forgotOpen}>
                  <Alert onClose={() => {setForgotOpen(false);}}>
                    Forgot your password? Boy, that's rough... Someone should probably do something about that. Well, good luck!
                  </Alert>
                </Collapse>
                <Button
                  fullWidth
                  variant="text"
                  sx={{ mt: 1, mb: 0 }}
                  onClick={() => {
                    setForgotOpen(true);
                  }}
                >
                  FORGOT PASSWORD
                </Button>
              </Box>
          </Grid>
          <Button
            fullWidth
            variant="outlined"
            sx={{ mt: 1, mb: 0 }}
          >
            CREATE ACCOUNT
          </Button>
        </Container>
      </ThemeProvider>
    </div>
  );
}

export default App;
